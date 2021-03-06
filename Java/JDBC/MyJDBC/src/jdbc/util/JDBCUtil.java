package jdbc.util;

import com.alibaba.druid.pool.DruidDataSourceFactory;
import jdbc.dao.IResultSetHandler;
import jdbc.dao.impl.DemoResHandleImpl_01;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class JDBCUtil {

//	// 加载数据库驱动
//	public static final String driver = "com.mysql.cj.jdbc.Driver";
//	// 获取数据库连接地址
//	public static final String url = "jdbc:mysql://localhost/demo?&useSSL=false&serverTimezone=UTC" +
//			"&rewriteBatchedStatements=true";
//	// 数据名称
//	public static final String username = "root";
//	// 数据库密码
//	public static final String password = "1234";

	// 数据库连接池
	public static DataSource ds = null;
	// 获取配置文件的地址
	public static final String PropertiesFilePath = "resource/db_info.properties";

	//加载驱动，静态代码块，保证加载类后只加载一次
	static{
		//1.加载配置文件
		Properties pt = new Properties();
		FileInputStream in = null;
		try {
			in = new FileInputStream(PropertiesFilePath);
			pt.load(in);
			//ds = BasicDataSourceFactory.createDataSource(pt);
			ds = DruidDataSourceFactory.createDataSource(pt);
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				if(in != null)
				in.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

//		ds = new BasicDataSource();
//		ds.setDriverClassName(driver);
//		ds.setUsername(username);
//		ds.setPassword(password);
//		ds.setUrl(url);
//		try {
//			Class.forName(driver);
//		} catch (ClassNotFoundException e) {
//			e.printStackTrace();
//		}

	}
	// 获取数据库连接
	public Connection getConnection()  {
		try {
			return  ds.getConnection();
			//return DriverManager.getConnection(url, username, password);
		} catch (Exception e) {
			e.printStackTrace();
		}
		return null;
	}
	// 判断数据库是否连接成功
	public void isConnection(Connection conn){
		if (conn != null) {
			System.out.println("数据库能正常连接！");
		} else
			System.out.println("数据库连接失败！");
	}
	// 执行并查看DML操作结果
	public void executeUpdate(String sql , Object...params){
		Connection conn = getConnection();
		PreparedStatement pst = null;
		DemoResHandleImpl_01 demoResHandle = new DemoResHandleImpl_01();
		try {
			pst = conn.prepareStatement(sql);
			for (int i = 0;i<params.length;i++) {
				pst.setObject(i+1,params[i] );
			}
			if(pst.executeUpdate() > 0) {
				System.out.println("Successfully executeUpdate！");
			}
		} catch (Exception e) {
			System.out.println("Failed to executeUpdate！");
			e.printStackTrace();
		} finally {
			closeSQL(conn, pst);
		}
	}
	// 执行并查看DQL操作结果
	public <E> E executeQuery(String sql , IResultSetHandler<E> handler, Object...params){
		Connection conn = getConnection();
		PreparedStatement pst = null;
		ResultSet rs = null;
		try {
			pst = conn.prepareStatement(sql);
			for (int i = 0;i<params.length;i++) {
				pst.setObject(i+1,params[i] );
			}
			rs = pst.executeQuery();
			return  handler.handle(rs);

//			while (rs.next()) {
//				Demo demo = new Demo();
//				demo.setId(rs.getInt("id"));
//				demo.setName(rs.getString("name"));
//				demo.setAge(rs.getInt("age"));
//				list.add(demo);
//			}
		} catch (Exception e) {
			System.out.println("Failed to executeQuery！");
			e.printStackTrace();
		} finally {
			closeSQL(conn,pst,rs);
		}
		return null;
	}

	// 关闭数据库连接的资源
	public void closeSQL(Connection conn,Statement st)  {
		if (st != null) {
			try {
				st.close();
			} catch (SQLException e) {
				System.out.println("Statement shutdown failed！");
				e.printStackTrace();
			}
		}
		if (conn != null) {
			try {
				conn.close();
			} catch (SQLException e) {
				System.out.println("Connection shutdown failed！");
				e.printStackTrace();
			}
		}
	}
	// 关闭数据库连接的资源
	public void closeSQL(Connection conn,Statement st,ResultSet rs)  {
		if (rs != null) {
			try {
				rs.close();
			} catch (SQLException e) {
				System.out.println("ResultSet shutdown failed！");
				e.printStackTrace();
			} finally {
				closeSQL(conn, st);
			}
		}
	}
	// 查看数据库资源是否关闭成功
	public void isCloseConnection(Connection conn){
		try {
			if (conn.isClosed()) {
				System.out.println("数据库能正常关闭！");
			} else
				System.out.println("数据库关闭失败!");
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
package jdbc.test;

import jdbc.util.JDBCUtil;
import org.junit.Test;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DBCPTest {
    @Test
    public void test01(){
//      BasicDataSource ds = new BasicDataSource();
//      ds.setDriverClassName(JDBCUtil.driver);
//      ds.setUsername(JDBCUtil.username);
//      ds.setPassword(JDBCUtil.password);
//      ds.setUrl(JDBCUtil.url);
        Connection conn = null;
        Statement st=null;
        ResultSet rs = null;
        String sql = "select * from demo";
        try {
            conn = new JDBCUtil().getConnection();
            st = conn.createStatement();
            rs = st.executeQuery(sql) ;
            while (rs.next()){
                String name = rs.getString("name");
                int age = rs.getInt("age");
                System.out.println("name = "+name+" , age = "+age);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            new JDBCUtil().closeSQL(conn, st, rs);
        }
    }

}

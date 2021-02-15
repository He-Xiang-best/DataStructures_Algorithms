package jdbc.test;

import java.sql.Connection;
import java.util.List;

import org.junit.Test;

import jdbc.dao.IDemo;
import jdbc.dao.impl.DemoDaoImpl;
import jdbc.domain.Demo;
import jdbc.util.JDBCUtil;

public class AllTest {

    static IDemo dao = new DemoDaoImpl();
    static Demo demo = new Demo();
    static JDBCUtil db = new JDBCUtil();
    @Test
    //数据库连接测试
    public void connectionTest() throws Exception {
        Connection conn = db.getConnection();
        db.isConnection(conn);
        System.out.println("--------------");
        conn.close();
        db.isCloseConnection(conn);
    }
    public Demo setInfo(){
        demo.setName("李华");
        demo.setAge(25);
        //demo.setId(14);
        return demo;
    }
    @Test
    public void saveTest(){
        dao.save(setInfo());
    }
    @Test
    public void deleteTest(){
        dao.delete(20);
    }
    @Test
    public void updateTest(){
        dao.update(setInfo(),20);
    }
    @Test
    public void getTest(){
        System.out.println(dao.get(5));
    }
    @Test
    public void getAllTest(){
        List<Demo>list = dao.getAll();
        for (Demo demo1 : list) {
            System.out.println(demo1);
        }
    }
    @Test
    public void countTest(){
        System.out.println( dao.getCount());
    }

}


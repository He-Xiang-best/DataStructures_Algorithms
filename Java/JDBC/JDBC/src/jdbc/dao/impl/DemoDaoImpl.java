package jdbc.dao.impl;

import jdbc.dao.IDemo;
import jdbc.domain.Demo;
import jdbc.util.JDBCUtil;
import org.apache.commons.dbutils.handlers.BeanHandler;
import org.apache.commons.dbutils.handlers.BeanListHandler;

import java.sql.SQLException;
import java.util.List;

public class DemoDaoImpl implements IDemo {
    static JDBCUtil db = new JDBCUtil();


    @Override
    public void save(Demo demo) {
        String sql = "insert into demo(name,age) values(?,?)";
        try {
            db.getQueryRunner().update(sql,demo.getName(),demo.getAge());
            System.out.println("Successfully save！");
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Failed to save！");
        }
    }

    @Override
    public void update(Demo demo, int id) {
        String sql = "update demo set name = ? , age = ? where id = ?";
        try {
            db.getQueryRunner().update(sql,demo.getName(),demo.getAge(),id);
            System.out.println("Successfully update！");
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Failed to update！");
        }

    }

    @Override
    public void delete(int id) {
        String sql = "delete from demo where id = ?";
        try {
            db.getQueryRunner().update(sql,id);
            System.out.println("Successfully delete！");
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Failed to delete！");
        }
    }

    @Override
    public Demo get(int id) {
        String sql = "select * from demo where id =?";
        try{
            return  db.getQueryRunner().query(sql, new BeanHandler<>(Demo.class),id);
        }catch(Exception e){
            System.out.println("Failed to get this information！");
            e.printStackTrace();
        }
       return null;
    }

    @Override
    public List<Demo> getAll() {
        String sql = "select * from demo";
        try{
            return  db.getQueryRunner().query(sql, new BeanListHandler<>(Demo.class));
        }catch(Exception e){
            System.out.println("Failed to get these information！");
            e.printStackTrace();
        }
        return null;
    }

}

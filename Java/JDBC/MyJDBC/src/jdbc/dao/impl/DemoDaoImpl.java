package jdbc.dao.impl;

import jdbc.dao.IDemo;
import jdbc.domain.Demo;
import jdbc.util.JDBCUtil;

import java.util.List;

public class DemoDaoImpl implements IDemo {
    static JDBCUtil db = new JDBCUtil();

    @Override
    public void save(Demo demo) {
        String sql = "insert into demo(name,age) values(?,?)";
            db.executeUpdate(sql,demo.getName(),demo.getAge());
    }

    @Override
    public void update(Demo demo, int id) {
        String sql = "update demo set name = ? , age = ? where id = ?";
        db.executeUpdate(sql,demo.getName(),demo.getAge(),id);
    }

    @Override
    public void delete(int id) {
        String sql = "delete from demo where id = ?";
        db.executeUpdate(sql,id);
    }

    @Override
    public Demo get(int id) {
        String sql = "select * from demo where id =?";
        return db.executeQuery(sql, new BeanHandler<>(Demo.class),id);
    }

    @Override
    public List<Demo> getAll() {
        String sql = "select * from demo";
        return ( db.executeQuery(sql, new BeanListHandler<>(Demo.class)));
    }

    @Override
    public Integer getCount() {
        String sql = "select count(*) as count from demo";
        return  db.executeQuery(sql, new DemoResHandleImpl_02());
    }

}

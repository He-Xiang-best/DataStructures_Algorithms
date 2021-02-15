package jdbc.dao.impl;

import jdbc.dao.IResultSetHandler;
import jdbc.domain.Demo;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class DemoResHandleImpl_01 implements IResultSetHandler<List<Demo>> {
    @Override
    public List<Demo> handle(ResultSet rs) throws SQLException {
        List<Demo> list = new ArrayList<>();
        while (rs.next()) {
            Demo demo = new Demo();
            demo.setId(rs.getInt("id"));
            demo.setName(rs.getString("name"));
            demo.setAge(rs.getInt("age"));
            list.add(demo);
        }
        return list;
    }
}

package jdbc.dao.impl;

import jdbc.dao.IResultSetHandler;

import java.sql.ResultSet;

public class DemoResHandleImpl_02 implements IResultSetHandler<Integer> {
    @Override
    public Integer handle(ResultSet rs) throws Exception {
        if (rs.next()){
            return rs.getInt("count");
        }
        return 0;
    }
}

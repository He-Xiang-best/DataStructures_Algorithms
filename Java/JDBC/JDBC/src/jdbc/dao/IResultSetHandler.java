package jdbc.dao;

import java.sql.ResultSet;

public interface IResultSetHandler<E> {
     E handle(ResultSet rs) throws Exception;
}

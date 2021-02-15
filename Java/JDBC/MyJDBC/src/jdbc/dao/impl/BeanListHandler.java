package jdbc.dao.impl;

import jdbc.dao.IResultSetHandler;

import java.beans.BeanInfo;
import java.beans.Introspector;
import java.beans.PropertyDescriptor;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class BeanListHandler<E> implements IResultSetHandler<List<E>> {
    public Class<E>  classType;

    public BeanListHandler(Class<E> classType){
        this.classType = classType;
    }

    @Override
    public List<E> handle(ResultSet rs) throws Exception {
        List<E> list = new ArrayList<>();
        while (rs.next()){
            //创建一个对象
            E obj = this.classType.newInstance();
            //通过内省来拿属性
            BeanInfo bf = Introspector.getBeanInfo(classType,Object.class);
            //获取所有属性的描述器
            PropertyDescriptor[] pds = bf.getPropertyDescriptors();
            //遍历每一个属性的描述器
            for (PropertyDescriptor pd : pds) {
                Object val = rs.getObject(pd.getName());
                //给对象设置属性
                pd.getWriteMethod().invoke(obj, val);
            }
            list.add(obj);
        }
        return list;
    }
}

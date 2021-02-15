package jdbc.dao;

import jdbc.domain.Demo;

import java.util.List;

public interface IDemo {
    // 1.保存数据
    void save(Demo dem);
    // 2.修改指定信息
    void update(Demo dem,int id);
    // 3.删除信息
    void delete(int id);
    // 4.获取指定数据
    Demo get(int id);
    // 5.获取所有数据
    List<Demo> getAll();
}

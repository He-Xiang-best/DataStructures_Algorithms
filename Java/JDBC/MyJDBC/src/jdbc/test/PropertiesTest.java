package jdbc.test;

import org.junit.Test;

import java.io.FileInputStream;
import java.util.Properties;

public class PropertiesTest {
    @Test
    public void test01(){
        final String filePath = "resource/db_info.properties";
        Properties pt = new Properties();
        FileInputStream in;
        try {
            in = new FileInputStream(filePath);
            pt.load(in);
            System.out.println("Messages following are:");
            System.out.println(pt.getProperty("driverClassName"));
            System.out.println(pt.getProperty("url"));
            System.out.println(pt.getProperty("username"));
            System.out.println(pt.getProperty("password"));
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

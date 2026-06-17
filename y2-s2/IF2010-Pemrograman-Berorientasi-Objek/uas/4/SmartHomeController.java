import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Collections;

public class SmartHomeController {

    private SmartHomeController() {}

    public static void printStatus(Object device) {
        Field[] fields = device.getClass().getDeclaredFields();
        for (Field f : fields) {
            f.setAccessible(true);
            try {
                System.out.println(f.getName() + " = " + f.get(device));
            } catch (Throwable t) {
                System.out.println("FIELD_ACCESS_ERROR");
            }
        }
    }

    public static void printCommands(Object device) {
        Method[] methods = device.getClass().getDeclaredMethods();
        ArrayList<String> names = new ArrayList<String>();
        for (Method m : methods) {
            names.add(m.getName());
        }

        Collections.sort(names);
        for (String name : names) {
            System.out.println(name);
        }
    }

    public static void execute(Object device, String command) {
        Class<?> clazz = device.getClass();

        try {
            Method method = clazz.getDeclaredMethod(command);
            method.setAccessible(true);
            method.invoke(device);
        } catch (NoSuchMethodException e) {
            System.out.println("COMMAND_NOT_FOUND");
        } catch (Exception e) {
            System.out.println("COMMAND_EXECUTION_ERROR");
        }
    }
}

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

import net.java.games.input.Component;
import net.java.games.input.Controller;
import net.java.games.input.ControllerEnvironment;

public class Joystick {
    private ArrayList<Controller> foundControllers;

    public static void main(String[] args) throws Exception {
        new Joystick();

    }

    public Joystick() throws Exception {
        foundControllers = new ArrayList<>();
        searchForControllers();

        if (!foundControllers.isEmpty()) {
            int no = 0;
            for (Controller c : foundControllers) {
                System.out.print(no++);
                System.out.println(" " + c.getName());
            }
            showControllerData(foundControllers.get(0));

        } else {
            System.out.println("No Controllers Found!");
        }

    }

    private void searchForControllers() {
        Controller[] controllers = ControllerEnvironment.getDefaultEnvironment()
                .getControllers();

        for (int i = 0; i < controllers.length; i++) {
            Controller controller = controllers[i];

            if (

            controller.getType() == Controller.Type.STICK
                    || controller.getType() == Controller.Type.GAMEPAD
                    || controller.getType() == Controller.Type.WHEEL
                    || controller.getType() == Controller.Type.FINGERSTICK) {
                // Add new controller to the list of all controllers.
                foundControllers.add(controller);

            }
        }

    }

    private void showControllerData(Controller controller) throws Exception {

        Component[] components = controller.getComponents();
        /*
         * Y Axis y X Axis x Y Rotation ry X Rotation rx Z Axis z Button 0 0
         * Button 1 1 Button 2 2 Button 3 3 Button 4 4 Button 5 5 Button 6 6
         * Button 7 7 Button 8 8 Button 9 9 Hat Switch pov
         *
         */

        InetAddress IPAddress = InetAddress.getByName("143.215.110.127");
        byte[] sendData = new byte[15];

        DatagramSocket clientSocket = new DatagramSocket();

        for (Component cc : components) {
            System.out.println(cc.getName() + " " + cc.getIdentifier());
        }

        while (true) {
            if (!controller.poll()) {
                break;
            }

            // I'm well aware of the fact that his value is zero by default.
            int ystick1 = 0;
            int xstick1 = 0;
            int throttle = 0;

            ystick1 = Math.round(components[0].getPollData() * 1000f) / 10;
            xstick1 = Math.round(components[1].getPollData() * 1000f) / 10;
            throttle = Math.round(components[4].getPollData() * 1000f) / 10;

            // The XBOX controller gives a max of 0.996 to Z axis, therefore you
            // might have to write a calibration algorithm In the future.
            /*
             * System.out.print("Throttle is: "); System.out.println(throttle);
             * System.out.print("X: "); System.out.println(xstick1);
             * System.out.print("Y: "); System.out.println(ystick1);
             */
            char throttle_direction = 'F';
            char turn_direction = 'L';

            if (xstick1 >= 0) {
                turn_direction = 'R';
            } else if (xstick1 < 0) {
                xstick1 = xstick1 * -1; // sign change bitchess
                turn_direction = 'L';
            }

            if (throttle < 0) {
                throttle_direction = 'B';
                throttle = throttle * -1;
            } else if (throttle >= 0) {
                throttle_direction = 'F';
                // no need to change signs its already positive.
            }

            String send = "*T:" + throttle_direction + "-"
                    + Integer.toString(throttle) + "*D:" + turn_direction + "-"
                    + Integer.toString(xstick1) + "*";

            System.out.println(send);
            if (throttle > 5) {
                sendData = send.getBytes();
                DatagramPacket sendPacket = new DatagramPacket(sendData,
                        sendData.length, IPAddress, 5005);

                clientSocket.send(sendPacket);
            }
            // clientSocket.close();
            try {
                Thread.sleep(200);
            } catch (InterruptedException ex) {
                Logger.getLogger(Joystick.class.getName()).log(Level.SEVERE,
                        null, ex);
            }
        }

    }
}

# CarMaker Ros2 Interface Tutorial  

In the second tutorial, you will use all your knowledge to move the ROS2 package `pse_aeb` into its own container. Use the basic workspace, copy/merge the package `pse_aeb` and the required message types into it. Build and run the AEB package and try to communicate with the CarMaker simulation.

## Prerequisites  

Before you can dive into the actual tutorial, you need to set up your environment. This includes installing the necessary software and dependencies. As already introduced, we use VSCode Tasks to help you with the setup.

### Create a Virtual Environment and Install Dependencies  

Press <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>P</kbd> to open the command palette and type "Tasks: Run Task". Select the task "Setup Environment". This will create a virtual environment and install all necessary dependencies for the CarMaker ROS2 interface.

### Build the CarMaker ROS2 Interface  

To build the CM ROS2 interface and the CM simulation, you can simply use the VSCode task "Build CarMaker and ROS2 Interface". This will build the CM simulation and the CM ROS2 interface. By pressing <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>P</kbd> and selecting "Tasks: Run Task", you can select the task "Build CarMaker and ROS2 Interface" or press <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>B</kbd>. This will build the CM simulation and the CM ROS2 interface.

### Run the CarMaker ROS2 Interface  

To run the CM ROS2 interface, you need to start the CM simulation. You can do this by pressing <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>P</kbd> and selecting "Tasks: Run Task", and then selecting the task "Run CarMaker". This will start the CM simulation and the CM ROS2 interface. You will be asked for a number. This number is used as the ROS2 domain ID. Use the last two digits of your student ID.

## Task

The interface uses the solution from the first tutorial. You can have a look at the [cm_ros_if.cpp](02_CarMaker_ROS2/ros2_ws/src/cm_ros_if/src/cm_ros_if.cpp). The CM interface will not launch the `pse_aeb` package directly. Instead, you have to run your own container. Otherwise, CM will throw an error due to synchronization issues.

Create a new container using the [basic workspace](https://gitlab.itiv.kit.edu/pse/templates) from the previous tutorials or from the templates repository, along with the provided `pse_aeb` package. The container should be capable of running the `pse_aeb` package and communicating with the CM simulation.


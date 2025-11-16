# How to Install
## Acknowledgments
## The way I took:
This guide is based on the official [micro-ROS documentation](https://micro.ros.org/docs/tutorials/core/first_application_linux/).

## Recommended Setup
I used **Ubuntu 22.04**, and I strongly recommend using the same version for compatibility.

## 1. Install the micro-ROS Build System
Once you have a ROS 2 installation on your computer, follow these steps:

   ```bash
   source /opt/ros/$ROS_DISTRO/setup.bash
   cd STM32Cube/
   mkdir microros_ws
   cd microros_ws
   git clone -b $ROS_DISTRO https://github.com/micro-ROS/micro_ros_setup.git src/micro_ros_setup
   sudo apt update && rosdep update
   rosdep install --from-paths src --ignore-src -y
   sudo apt-get install python3-pip
   colcon build
   source install/local_setup.bash
   ```

## 2. Create a New Firmware Workspace
   ```bash
   ros2 run micro_ros_setup create_firmware_ws.sh host
   ```

## 3. Build the Firmware
   ```bash
   ros2 run micro_ros_setup build_firmware.sh
   source install/local_setup.bash
   ```
   ### Note: This process may take a few minutes.

## 4. Create the micro-ROS Agent
   ```bash
   ros2 run micro_ros_setup create_agent_ws.sh
   ros2 run micro_ros_setup build_agent.sh
   source install/local_setup.bash
   ```

## 5. micro-ROS Repository(Humble_Branch)
   For more information, visit the [micro-ROS_STM32CubeMX_utilities_repository](https://github.com/micro-ROS/micro_ros_stm32cubemx_utils/tree/humble?tab=readme-ov-file#)

## 6. Using This Package with STM32CubeIDE
### 6.1. Clone this repository into your STM32CubeIDE project folder.
### 6.2. Go to Project → Settings → C/C++ Build → Settings → Build Steps Tab and add the following in Pre-build steps:
   ```bash
   docker pull microros/micro_ros_static_library_builder:humble && docker run --rm -v ${workspace_loc:/${ProjName}}:/project --env MICROROS_LIBRARY_FOLDER=micro_ros_stm32cubemx_utils/microros_static_library_ide microros/micro_ros_static_library_builder:humble
   ```
### 6.3. Add the micro-ROS include directory: Project → Settings → C/C++ Build → Settings → Tool Settings → MCU GCC Compiler → Include paths
   ```bash
   ../micro_ros_stm32cubemx_utils/microros_static_library_ide/libmicroros/include
   ```
### 6.4. Add the micro-ROS precompiled library: Project → Settings → C/C++ Build → Settings → MCU GCC Linker → Libraries: Library search path (-L):
   ```bash
   ../micro_ros_stm32cubemx_utils/microros_static_library_ide/libmicroros
   ```
### 6.5. Libraries (-l): 
   ```bash
   microros
   ```
### 6.6. Copy extra sources:
   ```bash
   micro_ros_stm32cubemx_utils/extra_sources/* to {your_Project}/core/src/
   ```
   ### Note: If using FreeRTOS, ensure the micro-ROS task stack is >10 kB or 3000 on stack size.

## 7. Install Docker
   ```bash
   sudo apt update
   sudo apt upgrade -y
   sudo apt install ca-certificates curl gnupg -y
   sudo install -m 0755 -d /etc/apt/keyrings
   curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
   sudo chmod a+r /etc/apt/keyrings/docker.gpg
   echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
   sudo apt update
   sudo apt install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin -y
   sudo docker run hello-world
   sudo usermod -aG docker $USER
   ```

## 8. Restart your computer
   ```bash
   docker ps
   ```

## 9. Grant Docker Socket Permissions
   ```bash
   sudo chmod 666 /var/run/docker.sock
   ```

## 10. Build and run your project

## 11. Good Luck

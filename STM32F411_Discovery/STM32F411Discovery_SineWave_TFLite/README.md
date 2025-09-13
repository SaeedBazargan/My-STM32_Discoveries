# How to Install
## Acknowledgments
Special thanks to **DevHeads** for their [tutorial video](https://www.youtube.com/watch?v=6XJ4M31ZvH0&list=PL2mKSkagAaJjjnVujAPwVsZobEfADTAxN&index=3)  
and **Shawn Hymel** for his [video](https://www.youtube.com/watch?v=gDFWCxrJruQ&t=742s).

## The way I took:
I used a Linux system for building TensorFlow Lite Micro, and I recommend you do the same:

1. Clone the repository:
   ```bash
   git clone https://github.com/tensorflow/tflite-micro.git

2. cd tflite-micro
3. ```bash
   make -f tensorflow/lite/micro/tools/make/Makefile TARGET=cortex_m_generic TARGET_ARCH=cortex-m4 microlite
For more details, [check the](https://github.com/tensorflow/tflite-micro/blob/main/tensorflow/lite/micro/cortex_m_generic/README.md) 
4. After building, you will get a file named **libtensorflow-microlite.a**.
**NOTE:**If you are working on Windows, copy this file over to your Windows environment.
5. add libtensorflow-microlite.a under Properties → C/C++ Build → Settings → MCU GCC Linker → Libraries in the STM32CubeIDE **(See the images below for detailed steps.)**

6. Run the project generation script to create a standalone TFLM tree:  
   ```bash
   python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py <desired_path>
for example:
   ```bash
   python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py ~/Mytflm/tflm-tree

7. A new folder with your chosen name will be created (e.g., Mytflm).This folder contains signal, tensorflow, and third_party.
**NOTE:**If you are working on Windows, you will also need to transfer this folder to your Windows environment.


## Output Example
![UART Output Screenshot](images/1.png)




Welcome to **My STM32 Discoveries**, a collection of projects and examples showcasing the capabilities of the STM32F411VE Discovery board and the STM32F746G-Discovey.  

## About  
This repository is designed to help you explore and learn the diverse functionalities and features of the STM32F411VE and STM32F746NG microcontrollers. Whether you're a beginner or an experienced developer, you'll find valuable examples and insights to expand your knowledge of STM32 development.  

## What's Inside  
- Projects demonstrating the key features of the STM32F411VE and STM32F746G-Discovey boards.  
- Examples highlighting real-world applications and solutions using STM32 MCUs.  
- Well-documented code for easy understanding and adaptation to your projects.  

## Getting Started  
1. Clone the repository:  
   ```bash
   git clone https://github.com/SaeedBazargan/My-STM32_Discoveries.git

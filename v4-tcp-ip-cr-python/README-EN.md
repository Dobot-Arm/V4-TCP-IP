Chinese version of the README -> please [click here](./README.md)

# Readme

## 1. The following steps are required to run Demo
1. The computer can be connected to the network port of the controller with a network cable, and then set a fixed IP, which is in the same network segment as the controller IP. The controller can also be connected wirelessly.

    - Nova Devices: Wired connection: ip is 192.168.5.1 ,Wireless connection: ip is 192.168.1.6 .

2. Try to ping the controller IP to make sure it is in the same network segment.

3. Numpy is required for the Python environment: `pip install numpy -i http://pypi.douban.com/simple/ --trusted-host pypi.douban.com`

4. files: Stores alarm ID related information

5. images：Store the image resources needed by the UI interface

## 2. File description
1. main.py: The entry point of the program.
   
2. dobot_api.py: It mainly encapsulates the robot interface, according to the robot TCP/IP remote control scheme (https://github.com/Dobot-Arm/TCP-IP-Protocol), modify it by yourself.

3. ui.py: The program runs the UI interface.
## 3. Run Demo
Method 1: If you need to detect and search the dynamic library, you need to open the entire directory in **VsCode**, and then run main.py directly.  

Method 2: To detect and search the dynamic library, you need to open the entire directory in **PyCharm**, and then run main.py directly.

## 4. Test environment
- language: Python 3.8 64-bit
- os: Windows 10 64-bit

## 5. Controller version
The controller versions that can use the TCP/IP protocol are as follows:
- Nova: V4.1 and above

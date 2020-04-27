
# Electronic Technologies and Biosensors Laboratory
### A.Y. 2019/2020 – II Semester

<p align="center">
   <a href="url"><img src="https://upload.wikimedia.org/wikipedia/it/archive/b/be/20151105101950%21Logo_Politecnico_Milano.png" height="50%" width="50%"></a>
</p>


## ASSIGNMENT 05
### PSoC I2C
1. **Objective**: 
In this assignment you are required to create 3 projects within a single workspace using PSoC Creator and the CY8CKIT-059 KIT along with the following components:
    * LIS3DH 3-Axis Accelerometer breakout board

2. **Context**:
* 2.1. Project 1 Implementing multiread and multiwrite functions
    * 2.1.1. Start from the final example (PSoC_03_Complete.zip) regarding the temperature sensor on the breakout board
    * 2.1.2. Add implementation of multiread and multiwrite functions in the I2C_Interface.c source file
    * 2.1.3. Substitute the single register readings in the for(;;) loop with a multiread
    * 2.1.4. Plot Temperature Data using Bridge Control Panel

* 2.2. Project 2 (due to 28th April) Testing the accelerometer output capabilities
    * 2.2.1. Correctly set the control registers of the LIS3DH accelerometer to output 3 Axis accelerometer data in Normal Mode at 100 Hz in the ±2.0 g FSR.
    * 2.2.2. Read Output registers at a correct frequency (verify new Data is available using StatusReg information). Carefully think about the possible options to read data at a constant rate.
    * 2.2.3. Convert the 3 axial outputs of the Accelerometer to 3 right-justified 16-bit integers with the correct scaling (i.e. in mg).
    * 2.2.4. Correctly setup the UART Serial Communication: is the baud rate you chose sufficient to keep up with the data acquisition? Perform the correct calculations and add some comments regarding your choice in the TopDesign of the project.
    * 2.2.5. Send the values to be plotted to Bridge Control Panel.
    * 2.2.6. Save the Bridge Control Panel .ini and .iic files as “HW_05_SURNAME_NAME_A.ini” and “HW_05_SURNAME_NAME_A.iic”.

* 2.3. Project 3 (due to 28th April) Reading accelerometer output in m/s2
    * 2.3.1. Correctly set the control register to output a 3 Axis Signal in High Resolution Mode at 100 Hz in the ±4.0 g FSR.
    * 2.3.2. Read Output registers at a correct frequency (verify StatusReg). As for Project 2, carefully think about the possible options to read data at a constant rate.
    * 2.3.3. Convert the 3 axial outputs of the Accelerometer to a floating point in m/s2 units.
    * 2.3.4. Cast the floating point values to an int variable without losing information, keeping at least 3 decimals. What is a standard technique to perform such a task?
    * 2.3.5. Correctly setup the UART Serial Communication: is the baud rate you chose sufficient to keep up with the data acquisition? Perform the correct calculations and add some comments regarding your choice in the TopDesign of the project.
    * 2.3.6. Send the values to be plotted to Bridge Control Panel in m/s2.
    * 2.3.7. Save the Bridge Control Panel .ini and .iic files as “HW_05_SURNAME_NAME_B.ini” and “HW_05_SURNAME_NAME_B.iic”.

I2C is a multi-master  multi-slave, half duplex, synchronous communication protocol.

The i2c communication uses data (DOUT / SDA) and clock(CLK / SCL) pins for data transfer.

Properties:

          I2C follows master-slave architecture in which the master drives the bus.

          Master-slave architecture could be:

              > Multi-Master Multi-Slave

              > Single-Master Multi-Slave

              > Single-Master Single-Slave


Every slave has a 7-bit address which allows master to identify specific slave from multiple slaves

A maximum of 128 slaves can be connected to single i2c bus. Master sends 8-bit (7-bit slave address
and 8th bit is read/write operation indication).

The available code is used to list out header addresses of multiple slaves connected to single i2c bus.
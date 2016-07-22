# NetVision
Creates a map of all the devices on a network and the transporation between them.


# Compilation

First, install libtins. It is already included as a submodule.
Before compiling, libtins requires libpcap.
For Debian based systems(Ubuntu, Linux Mint, etc), you can install them by executing this command as root:
```
apt-get install libpcap-dev libssl-dev cmake
```
For Red Hat based systems(RHEL, Fedora, CentOS, etc), you can install them by executing the following command as root:
```
yum install libpcap-devel openssl-devel cmake
```



Now, cd into the libtins folder and execute these commands:
```
mkdir build
cd build
cmake ../ -DLIBTINS_ENABLE_CXX11=1
make
sudo make install
sudo ldconfig
```

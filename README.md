# swing_balancer

## How to compile

### The easy way

``` console
$ make
```

### The advanced way

``` console
$ mkdir build
$ cd build
$ cmake .. [OPTIONS]
$ make
```

## Useful make targets

### Upload `.bin` file

``` console
$ make upload_<project_name>
```

### Connect over serial port

``` console
$ make connection_over_serial_port
```

### Connect over virtual COM port

``` console
$ make connection_over_virtual_com_port
```

### List all targets

``` console
$ make help
```

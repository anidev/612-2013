# FIRST Team 612 Chantilly Robotics - Code for FRC 2013 Competition (Ultimate Ascent)

### Usage

For now, this project assumes that you already have [ucpp][1] installed and
configured for your system.  The build process is as follows:

    $ ucpp init               #run once
    $ ucpp configure          #run each time the files in the project have changed
    $ make                    #compile and link all code (debug)
    $ make DEBUG_MODE=0       #compile and link all code (release)
    $ make deploy             #deploy code to robot

### Configuring

> * When imaging it is necessary to select the option for WindRiver C++, and please enable NetConsole (except for in perhaps release builds).
> * Remember that the cRIO runs an ftp server that allows anonymous ftp access.
> * The robot needs to be imaged with version 43 of the firmware to be legal.

### License

All code in this project is licensed under the ISC License (see 'LICENSE.rst')
and is Copyright © 2013 Chantilly Robotics unless otherwise noted.

### Contributors

A full list of contributors is in 'AUTHORS.rst'.

### Thanks
Thanks go out to nikitakit and all the other developers of the [ucpp][1] project.
Thanks to [github][2] for providing hosting of our code.
And finally, a big thanks to the entire organization of [FIRST][3].

[0]: http://anidev.github.com/612-2013/docs/html
[1]: https://github.com/nikitakit/ucpp
[2]: https://github.com/
[3]: http://usfirst.org/

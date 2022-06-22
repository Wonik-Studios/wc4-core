# wc4-core
WC4 which is short for Wonik Connect 4 Is a complex minimax algorithm that decides the best moves in the classical game Connect 4. Refer to the full introduction & showcase available on https://wonik.tech/project/wc4

# Usage Instructions

WC4 can be used as a node addon, as it was made to be used in a NodeJS app. However inside *wonikconnect4.cpp*, the "ConnectFourAI" class is independant and to use it independantly as a C++ class you are able to just copy the entire class leaving the mmai_wrapper out of it.

### Downloading the Repository & Building for NodeJS:
* **Prerequisite Software for NodeJS compilation:**
* *NodeJS*
* *node-gyp*
* *build-essentials (Linux)*
* *MinGW (Windows)*

You can either download the source code for the release you want to use, or you can clone the repository via:

    git clone https://github.com/Wonik-Studios/wc4-core.git

Once you've cloned or unzipped the release, cd into it.

    cd wc4-core

Once the following steps are complete, it is time to compile it into a native .node addon. Make sure you have **build-essentials** installed for Linux compilation and **MinGW** installed for Windows compilation.

    node-gyp configure
    node-gyp build

The final .node binary should then be created under *build/Release/wc4.node*.
You can now use wc4.node independantly in any NodeJS application through the **ai()** and **winCheck()** functions. The parameters for these functions are really straight forward and can be seen inside the initial *wonikconnect4.cpp* file where the functions are defined.

sudo apt-get update
sudo apt-get install gnuplot

clear_lib(){
    rm lib/*.a 2>/dev/null
}

remove_dir(){
    if [ -d build ] 
    then
        rm build -rf
    fi
    
    if [ -d res ] 
    then
        rm res -rf
    fi
    clear_lib
}


build_test(){
    echo "===================== build test start ====================="
    echo
    
    remove_dir
    mkdir build

    cd build
    cmake ../

    make install


    cd ..
    rm build -rf

    mkdir res

    cd bin
    ./Server
}

test(){
    build_test
}


test

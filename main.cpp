#include "Reversi.h"

int main(int argc, char** argv){
    Reversi reversi;
    bool success = reversi.Initialize();
    if(success){
        reversi.RunLoop();
    }
    reversi.Shutdown();
    return 0;
}
#include "../include/interpretador.h"
#include "../include/interface.h"


int main(){


    SGV sgv = initSGV();
    int running = 1;
    while (running == RUN)
    {
        running = interpreter(sgv);
    }


    destroySGV(sgv);


    return 0;
}

#include <time.h>
#include "datetime.h"

int get_timestamp() {
    return (int)time(NULL);
}
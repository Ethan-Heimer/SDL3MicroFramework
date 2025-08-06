#ifndef UTIL_ERRORS
#define UTIL_ERRORS


enum ERRORS{
    SUCCSESS = 0, 
    WINDOW_NOT_INIT,
    RENDERER_NOT_INIT,
    TEXTURE_ERROR
};

void LogError(ERRORS error);

#endif

#include <stdio.h>
#include <Python.h>

int main()
{
    //initialize python & check
    Py_Initialize();
    if ( !Py_IsInitialized() )
    {
        return -1;
    }

    //import py system environment and pyfile location
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/pixy/pixywerk/qtproj/cp1')");

    //variable initialize
    PyObject *pModule = NULL, *pFunc = NULL,*pArg = NULL;

    //import python module (name of pyfile)
    pModule = PyImport_ImportModule("pytt");
    if (!pModule) {
        printf("Cant open python file!\n");
        return -1;
        }

    //(optional)check if the function is in the pyfile/module
    int functst = PyObject_HasAttrString(pModule,"hello");
    if(!functst){
        printf("func do not exist\n");
        return -1;
        }

    //introduce the fuction from module/pyfile
    pFunc= PyObject_GetAttrString(pModule,"hello");
    if(!pFunc){
        printf("Get function hello failed\n");
        return -1;
    }

    //set the argument for input, if none, use NULL in next phrase
    pArg = Py_BuildValue("(s)","Lockon");

    //use the python function
    PyEval_CallObject(pFunc,pArg);

    Py_Finalize();

    return 0;
}

#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
private:
    char* datos;   
    int longitud;   
    int capacidad;  

    void redimensionar(int nuevaCapacidad);     
    void liberarMemoria();                      
    void copiarTexto(const char* texto);        

public:
    MyString();                         
    MyString(const char* texto);        
    MyString(const MyString& otro);     
    ~MyString();                        

    void asignar(const char* texto);    
    void concatenar(const char* texto); 
    int obtenerLongitud() const;        
    const char* obtenerTexto() const;  

    MyString& operator=(const MyString& otro); 
};

#endif
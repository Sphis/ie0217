# Nombre del programa de salida
TARGET = gestion_estudiantes.exe # Este es el ejecutable final que quiero tener

# Compilador de C++
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -std=c++11 # -Wall: Ensenar todos los warnings que hubieron
# a la hora de intentar de compilar, -std para indicar la version del compilador

# Lista de archivos fuente
SOURCES = estudianteMain.cpp estudiante.cpp

# Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:.cpp=.exe) # El <$> es para interpretar una variable definida previamente
# Lo que estoy haciendo es tomando todo lo de SOURCES que termina en .cpp y lo reemplazo con
# .exe y lo guardo en OBJECTS

# Regla para compilar los archivos fuente en archivos objeto
# Este pattern rule indica que cuando el make se encuentra un archivo con %.exe va a buscar
# un archivo con el mismo nombre, pero que termine en .cpp, si esto se cumple se ejecuta
# lo que hay indentado.
%.exe: %.cpp # "%" es para decir cualquier string
	$(CXX) $(CXXFLAGS) -c $< -o $@
# $< pasa el .cpp y $@ el .exe

# Regla para compilar el programa a partir de los archivos objeto
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para limpiar los archivos generados
clean:
	del $(TARGET) $(OBJECTS)

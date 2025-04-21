# Nombre del ejecutable
TARGET = uhr

# Compilador
CXX = g++

# Flags del compilador
CXXFLAGS = -std=c++11 -O0

# Archivos fuente
SRCS = uhr.cpp bruteforce.cpp distancia_euc.cpp divide_and_conquer.cpp

# Archivos objeto (automáticamente genera los .o)
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Cómo construir el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Cómo compilar cada archivo fuente a objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de archivos intermedios
clean:
	rm -f $(OBJS) $(TARGET)

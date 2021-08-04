
project(Source)



set(VECTOR_SRC Source.cpp CRat.cpp AutoTest.cpp)
set(VECTOR_HDR AutoTest.h CRat.h)


add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})

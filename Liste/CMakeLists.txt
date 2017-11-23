project(TestListe)
add_executable(TestListe liste_test.c liste.c liste.h)
target_link_libraries(TestListe m)
install(TARGETS TestListe RUNTIME DESTINATION ${BIN_DIR})
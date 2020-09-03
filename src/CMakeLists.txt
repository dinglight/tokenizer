set(LIB_SRC
    util.cc
    directed_acyclic_graph.cc
    sorted_table.cc
    tokenizer.cc
)

add_library(${PROJECT_NAME} SHARED ${LIB_SRC})

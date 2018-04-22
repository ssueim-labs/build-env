file( GLOB sources "*.cpp" "*.hpp" )

add_executable( bryllite-test ${sources} )
target_link_libraries( bryllite-test bryllite-utils ${Boost_LIBRARIES} )

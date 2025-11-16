project('pocket-racing-server', 'cpp',
    version : '0.1.0',
    meson_version : '>=1.3.2',
)

if host_machine.system() == 'windows'
    cpp_std_option = 'vc++latest'
elif host_machine.system() == 'linux'
    cpp_std_option = 'c++23'
else
    cpp_std_option = 'c++23'
endif

asio = dependency('asio')
websockets = dependency('websocketpp')
gtest = dependency('gtest')

if host_machine.system() == 'windows'
    add_project_arguments('-D_WIN32_WINNT=0x0601', language: 'cpp')
endif

src = files('bins/server.cpp')

lib = library('pocket-racing',
    files(
        'src/pocketracing.cpp'),
    dependencies: [asio, websockets],
    include_directories : include_directories('include/pocketracing'),
    cpp_args : ['-DPOCKETRACING_BUILDING_THE_LIB'],
    override_options: {'cpp_std': cpp_std_option}
)

dep = declare_dependency(
    link_with : lib,
    include_directories : include_directories('include')
)

executable('pocket-racing-server',
    src,
    dependencies: [asio, websockets, dep],
    include_directories: include_directories('include/pocketracing'),
    override_options: {'cpp_std': cpp_std_option}
)

tests_all = executable('tests-all',
    files('tests/all.cpp'),
    dependencies: [gtest, asio, websockets, dep],
    include_directories: include_directories('include/pocketracing'),
    override_options: {'cpp_std': cpp_std_option}
)

test('all', tests_all)

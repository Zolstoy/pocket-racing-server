project('pocket-racing-server', 'c',
  version : '0.1.0',
  default_options : ['warning_level=3'])

# Include directory
inc = include_directories('include')

# Build the racing library
racing_lib = static_library('racing',
  'src/racing.c',
  include_directories : inc,
  install : true)

# Build the server binary
server_exe = executable('pocket-racing-server',
  'src/server.c',
  include_directories : inc,
  link_with : racing_lib,
  install : true)

# Build and run tests
subdir('tests')

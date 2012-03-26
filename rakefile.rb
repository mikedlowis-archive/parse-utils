include Rake::DSL
require 'tools/rake_utils/source/library.rb'

#------------------------------------------------------------------------------
# Configuration Objects
#------------------------------------------------------------------------------
# Configuration for the static library
ParseUtilsStatic = Library.new({
    :name => 'libparse-utils.a',
    :output_dir => 'build/static',
    :compiler_options => [ '-c', '-Wall', '-o'],
    :source_files => [ 'source/**/*.c*' ],
    :include_dirs => [ 'source/**/' ],
})
ParseUtilsStatic.setup_default_rake_tasks()

# Configuration for the shared library
ParseUtilsShared = Library.new({
    :name => 'libparse-utils.so',
    :output_dir => 'build/shared',
    :compiler_options => [ '-c', '-Wall', '-fPIC', '-o'],
    :linker_bin => 'c++',
    :linker_options => ['-shared', '-o'],
    :source_files => [ 'source/**/*.c*' ],
    :include_dirs => [ 'source/**/' ],
})
ParseUtilsShared.setup_default_rake_tasks()

#------------------------------------------------------------------------------
# Release Tasks
#------------------------------------------------------------------------------
desc 'Execute a complete build including unit tests and binary'
task :default => [ :release ]

desc 'Build and link the binary'
task :release => [ ParseUtilsStatic.name(), ParseUtilsShared.name() ]


require 'rubygems'
require 'rake'
require 'rake/clean'
require "rake/extensiontask"

require 'bundler'
Bundler::GemHelper.install_tasks

require 'rspec/core/rake_task'
RSpec::Core::RakeTask.new(:spec) do |spec|
  spec.pattern = 'spec/**/*_spec.rb'
  spec.rspec_opts = '--backtrace'
end

RSpec::Core::RakeTask.new(:rcov) do |spec|
  spec.pattern = 'spec/**/*_spec.rb'
  spec.rcov = true
end

task :default => :spec

gem = Gem::Specification.load(File.dirname(__FILE__) + '/icu4r-next.gemspec')
Rake::ExtensionTask.new('icu', gem)

Rake::Task[:spec].prerequisites << :compile

#!/usr/bin/ruby -w

# data structures
graph = Hash.new      # map: num => count

# count each occurence
ARGF.each_line do |line|
  if graph[line.chomp] == nil
    graph[line.chomp] = 0
  end
  graph[line.chomp] += 1
end

# Output counts for each number
puts "Counts: "
graph.each do |num,count|
  puts "#{num}: #{count}"
end

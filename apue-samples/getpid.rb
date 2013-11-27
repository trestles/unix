
(0..10).each do |x|
  y=`./getpid`
  puts x.to_s + " and " + y.to_s
end

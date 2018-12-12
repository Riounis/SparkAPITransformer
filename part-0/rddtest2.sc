sc.textFile("helloworld.txt").map(line => 1:Long).reduce((a:Long, b:Long) => a+b)

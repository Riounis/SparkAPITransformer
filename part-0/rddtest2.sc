sc.textFile("helloworld.txt").map(line => 1).reduce((a:Int, b:Int) => a+b)

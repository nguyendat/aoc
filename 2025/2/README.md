# Install Kotlin runtime
brew install kotlin  

# Compile
kotlinc Solution.kt -include-runtime -d Solution.jar

# Run 
java -jar Solution.jar   
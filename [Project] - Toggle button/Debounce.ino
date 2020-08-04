boolean debounce(boolean last){
  //Local Variable
  boolean current = digitalRead(buttonPin);

  if(last != current){
    delay(5);  //5 milliseconds
    current = digitalRead(buttonPin);
  }
  return current;
}

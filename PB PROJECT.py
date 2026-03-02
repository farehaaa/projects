import time
import random

# List of sentences instead of words
sentence_list = [ "Python is diffcult yet fun.",
    "When life gives you lemons, make lemonade",
    "To be or not to be, that is the question",
    "The only way to do great work is to love what you do.",
    "Silence is better"
   ]

def generate_sentence():
    return random.choice(sentence_list)

def start_typing_test():
    sentence = generate_sentence()  
    print("\nTYPE THIS SENTENCE ACCURATELY AND FASTLY:\n")
    print(f"  {sentence}\n")
    print("Press Enter to start...")

    input()

    print("Start typing below...\n")

    typed_text, total_time = capture_typing(sentence)

    calculate_wpm(typed_text, sentence, total_time)

def capture_typing(sentence):
    start_time = time.time()  

    while True:
        typed_text = input(f"Type the sentence: {sentence}\nYour input: ")
        if typed_text == sentence:
            total_time = time.time() - start_time  
            break
        else:
            print("Type again as the sentence is incorrect")

    return typed_text, total_time

def calculate_wpm(typed_text, sentence, total_time):
    chars_typed = len(typed_text)
    words_typed = chars_typed / 5  # Average word length is 5 chars
    if total_time > 0:
        final_wpm = (words_typed / total_time) * 60
    else: final_wpm==0
    
    correct_chars = 0
    for i in range(min(len(typed_text), len(sentence))):
        is_correct = typed_text[i] == sentence[i]
        if is_correct:
            correct_chars += 1

    accuracy = (correct_chars / max(len(sentence), 1)) * 100

    print(f"\nTime Taken: {total_time:.2f} seconds")
    print(f"Words Per Minute: {final_wpm:.2f}")
    print(f"Accuracy: {accuracy:.2f}%")
start_typing_test()

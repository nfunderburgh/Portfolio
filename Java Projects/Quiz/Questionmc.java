
import java.util.Arrays;

/**
* Implements classes need to add a multiple choice question
* Functionality to our Quiz
*
* @author  Noah Funderburgh
* @version 1.0
* @since   3/3/2020
*/

public class Questionmc extends Question {
	/**
	 * This functions will show the answer when calling the function for multiple choice quesitons.
   	 */
	void showQuestion() {
		char charLookingFor = ':';
		int count = 0;
		char letter = 'A';
		String[] tokens = questionText.split("\\:");
		for (int i = 0; i < questionText.length(); i++) {
			if (questionText.charAt(i) == charLookingFor) {
				count++;
			}
		}
		count++;

		for (int i = 0; i < count; i++) {
			if (i == 0) {
				System.out.println(tokens[0] + "?");
			} else {
				System.out.println("    (" + letter + ") " + tokens[i]);
				letter++;
			}
		}
	}

//-------------------------------------------------------
	/**
	 * This function checks the if userAnswer is equal to Answer by making both strings lowercase
	 * and then comparing the two to check if there equal.
	 * 
	 * @param userAnswer answer thats input by the user in the quiz
	 * @return boolean returns true if there equal else it returns false.
   	 */
	boolean checkAnswer(String userAnswer) {
		userAnswer = userAnswer.toLowerCase();
		answerText = answerText.toLowerCase();
		
		char userArray[] = userAnswer.toCharArray();
		Arrays.sort(userArray);
		userAnswer = String.valueOf(userArray);
		
		String answer = answerText;
		char answerArray[] = answer.toCharArray();
		Arrays.sort(answerArray);
		answer = String.valueOf(answerArray);
	
		
		if(answer.equals(userAnswer)) {
			return true;
		}
		else {
			return false;
		}
	}
}

//-------------------------------------------------------
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

class Translator implements Runnable {
	
	public int progress;
	private int key;
	private BufferedReader bfr;
	private BufferedWriter bwr;
	private File inptf, outptf;
	private final Screen screen;
	public static final String ALPHABET = "abcdefghjiklmnopqrstuvwxyz";
	public static final String NOCK = "WIN_BXE";
	public static final char NIGHT = '`';
	public static final char DOUBLE_NIGHT = '@';
	public static final char SPACE = '|';
	
	Translator(Screen screen) throws IOException {
	
		inptf = new File("src/main/resources/outptf");
		outptf = new File("src/main/resources/showtptf");
		bfr = new BufferedReader(new FileReader(inptf));
		bwr = new BufferedWriter(new FileWriter(outptf));
		this.screen = screen;
	
	}
	
	private String convert(char c) {
		
		String result = "";
		switch(c) {
		
		case 'a':
			result += '<';
			for (int i = 0; i < (key + 2); i++)
				result += '$';
			for (int i = 0; i < (key * 2); i++)
				result += '^';
			break;
		case 'b':
			result += "??";
			for (int i = 0; i < key; i++)
				result += '!';
			break;
		case 'c':
			result += "^^^";
			for (int i = 0; i < (key + 1); i++)
				result += '!';
			break;
		case 'd':
			for (int i = 0; i < key; i++)
				result += '*';
			for (int i = 0; i < key; i++)
				result += '<';
			for (int i = 0; i < (key + 3); i++)
				result += '*';
			break;
		case 'e':
			for (int i = 0; i < (key + 5); i++)
				result += '%';
			result += "!$!";
			break;
		case 'f':
			result += ">>>";
			for (int i = 0; i < key; i++)
				result += '$';
			result += '!';
			break;
		case 'g':
			for (int i = 0; i < ((key * 2) + 24); i++)
				result += '*';
			result += "&<";
			break;
		case 'h':
			for (int i = 0; i < key; i++)
				result += '!';
			result += "$$!";
			break;
		case 'i':
			result += "%^";
			for (int i = 0; i < key; i++)
				result += '^';
			result += '%';
			break;
		case 'j':
			for (int i = 0; i < ((key / 2) + 16); i++)
				result+= '?';
			result += "*^^*";
			break;
		case 'k':
			for (int i = 0; i < key; i++)
				result += '^';
			for (int i = 0; i < key; i++)
				result += '*';
			result += "&&*";
			break;
		case 'l':
			result += "!!$$%%^^^";
			for (int i = 0; i < (key + 7); i++)
				result += '>';
			break;
		case 'm':
			for (int i = 0; i < key; i++)
				result += '&';
			result += '^';
			for (int i = 0; i < key; i++)
				result += '$';
			break;
		case 'n':
			result += "&^";
			for (int i = 0; i < (key * 3); i++)
				result += '^';
			break;
		case 'o':
			result += "<<";
			for (int i = 0; i < key; i++)
				result += '*';
			result += ">>&";
			break;
		case 'p':
			result += "<<<<";
			for (int i = 0; i < key; i++)
				result += '!';
			break;
		case 'q':
			for (int i = 0; i < (key - (key / 2) + (key / 4)); i++)
				result += '*';
			result += "&^";
			break;
		case 'r':
			result += "!$$";
			for (int i = 0; i < key; i++)
				result += '!';
			break;
		case 's':
			result += "?>";
			for (int i = 0; i < (key + 22); i++)
				result += '?';
			result += "!!";
			break;
		case 't':
			result += "%%";
			for (int i = 0; i < (key + 1); i++)
				result += '&';
			break;
		case 'u':
			result += "!!!!<";
			for (int i = 0; i < key; i++)
				result += '$';
			for (int i = 0; i < key; i++)
				result += '<';
			for (int i = 0; i < key; i++)
				result += '!';
			break;
		case 'v':
			result += "*^^";
			for (int i = 0; i < (key + 12); i++)
				result += '>';
			break;
		case 'w':
			for (int i = 0; i < (key * 4); i++)
				result += '$';
			break;
		case 'x':
			result += '<';
			for (int i = 0; i < key; i++)
				result += ">";
			result += "$$";
			for (int i = 0; i < key; i++)
				result += '%';
			break;
		case 'y':
			result += "!>>$";
			for (int i = 0; i < (key * 2); i++)
				result += '!';
			break;
		case 'z':
			result += "????!";
			for (int i = 0; i < key; i++)
				result += '$';
			result += '?';
			break;
		case ' ':
			result = "";
		case '\t':
			result = "";
		case '\n':
			result = "";
		case '.':
			result = "";
		case ',':
			result = "";
		case '"':
			result = "";
		case '?':
			result = "";
		case '-':
			result = "";
		case '_':
			result = "";
		case 39:
			result = "";
		case 33:
			result = "";
		case NIGHT:
			result = "";
		case DOUBLE_NIGHT:
			result = "";
		case SPACE:
			result = "";
			break;
		default:
			if (Character.isWhitespace(c)) {
				result = "";
			} else {
				System.out.println(c + "Only alphabet characters permitted. Quitting.");
				System.exit(1);
			}
		
		}
		return result;
		
	}

	private int getKey(String s) {
		
		for (int i = 0; i < ALPHABET.length(); i++)
			for (key = 1; key < 26; key++) 
				if (s.equals(convert(ALPHABET.charAt(i)))) 
					return key;
		return -1;

	}
	
	private char translate(String encoded) {
		
		for (int i = 0; i < ALPHABET.length(); i++) 
			if (encoded.trim().equals(convert(ALPHABET.charAt(i)).trim())) 
				return ALPHABET.charAt(i);
		return '1';    //signifies error
		
	}
	
	private String carrToString(char[] arr) {
		
		String result = "";
		for (char c : arr)
			result += c;
		return result;
		
	}
	
	public String getStringToTranslate() throws IOException {
	
		int c; 
		String toTranslate = "";
		while ((c = bfr.read()) != -1) 
			if (c != DOUBLE_NIGHT)
				toTranslate += (char) c;
		if (!(toTranslate.substring(0, 7).equals(NOCK))) 
			System.exit(1);
		return toTranslate;
	
	}
	
	public void run() {
		
		try {
		String ss = "";
		int it;
		char put;
		String toTranslate = getStringToTranslate();
		it = 7;   //begin checking characters AFTER nock
		while (1 == 1) {    //checks if ss fits a keygen and ONLY once it is determined that ss is equivalent to a whole codeword
			try {
				if (getKey(ss) != -1 && toTranslate.charAt(it) == SPACE)
					break;
			} catch (StringIndexOutOfBoundsException e) {
				break;
			}
			ss += toTranslate.charAt(it);
			it++;
		}
		key = getKey(ss);
		char[] sarr = new char[toTranslate.length()];
		put = 49;   //ASCII for the digit '1'
		for (int progress = 7; progress < toTranslate.length(); progress++) {
			if (toTranslate.charAt(progress) != SPACE && toTranslate.charAt(progress) != NIGHT)
				sarr[progress - 7] = toTranslate.charAt(progress);
			if (sarr.length >= 3)	//save a few extra translations, given that no alphabet character corresponds to an encode of less than three characters
				put = translate(carrToString(sarr));
			if (put != '1') {
				bwr.write(put);
				sarr = new char[toTranslate.length()];   //reset the array
			}
			screen.getBar().setValue(progress - 7);
			
		}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
}

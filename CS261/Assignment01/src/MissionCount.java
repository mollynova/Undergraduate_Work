import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.regex.Pattern;
import java.util.Map.Entry;

public class MissionCount
{
    // returns an InputStream that gets data from the named file
    private static InputStream getFileInputStream(String fileName) throws Exception
    {
	InputStream inputStream;

	try {
	    inputStream = new FileInputStream(new File(fileName));
	}
	catch (FileNotFoundException e) {		// no file with this name exists
	    inputStream = null;
	    throw new Exception("unable to open the file -- " + e.getMessage());
	}
	return inputStream;
    }
    

    public static void main(String[] args) {
	
	if (args.length != 1) {
	    System.out.println("USage: MissionCount <datafile>");
	    System.exit(1);
	}

	try {
	    System.out.printf("CS261 - MissionCount - Ensign Molly Novash%n%n");

	    InputStream log = getFileInputStream(args[0]);
	    Scanner sc = new Scanner(log);
	    sc.useDelimiter(Pattern.compile(",|\n"));
	    
	    // create double nested TreeMap<K, V> to hold data
	   TreeMap<String, TreeMap<String, Integer>> tmap = new TreeMap<String, TreeMap<String, Integer>>();
	    
	    while (sc.hasNext())
		{
		    String crewMember = sc.next();
		    String mission = sc.next();

		    // Add code to read in the data and store it in a data structure here
		    
		    // if the mission isn't in the map at all
		    if(!tmap.containsKey(mission)){
		    	// create a new TreeMap<String, Integer> for the person, and count = 1
		    	TreeMap<String, Integer> tmpEntry = new TreeMap<String, Integer>();
		    	tmpEntry.put(crewMember,  1);
		    	// insert mission and secondary treemap into primary treemap
		    	tmap.put(mission,  tmpEntry);
		    	
		    } else {
		    	// get a temp instance of the treemap of that mission
		    	TreeMap<String, Integer> tmpMap = tmap.get(mission);
		    	// if the person is not in tmpMap
		    	if(!tmpMap.containsKey(crewMember)){
		    		tmpMap.put(crewMember,  1);
		    		tmap.put(mission, tmpMap);
		    	} else {
		    		Integer newCount = tmpMap.get(crewMember);
		    		newCount++;
		    		
		    		// remove old record of member from mission
		    		tmpMap.remove(crewMember);
		    		tmpMap.put(crewMember, newCount);
		    		tmap.put(mission,  tmpMap);
		    	}
		    }
			
		}
	    sc.close();

	    // Add code to print the report here
	    for(Entry<String, TreeMap<String, Integer>> entry : tmap.entrySet()){
	    	String key = entry.getKey();
	    	TreeMap<String, Integer> interateCrew = tmap.get(key);
	    	// print mission name
	    	System.out.printf("%s\n:\n", key);
	    
	    	// for loop to go through crew members in each of these missions
	    	for(Entry<String, Integer> ent : interateCrew.entrySet()){
	    		String person = ent.getKey();
	    		Integer count = ent.getValue();
	    		
	    		// print crew member and count
	    		Integer length = person.length();
	    		Integer set = 27 - length;
	    		String spaces = "";
	    		for(Integer i = 0; i < set; i++){
	    			spaces += " ";
	    		}
	    		if(count > 9){
	    			spaces = spaces.substring(0, spaces.length() - 1);
	    		}
	    		
	    		System.out.printf("  %s", person);
	    		System.out.printf("%s%d", spaces, count);
	    		System.out.printf("\n");
	    	}
	    	System.out.printf("\n");
	    }

	} catch (Exception e) {
	    System.out.println("Error: " + e.getMessage());
	}
    }
}

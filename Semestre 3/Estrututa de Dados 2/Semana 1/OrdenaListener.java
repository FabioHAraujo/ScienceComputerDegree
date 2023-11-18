import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JCheckBoxMenuItem;


public class OrdenaListener implements ActionListener {

	public Frame frameOrdena;
	
	private JCheckBoxMenuItem mnBubbleSort;
	private JCheckBoxMenuItem mnInsertionSort;
	private JCheckBoxMenuItem mnSelectionSort;
	private JCheckBoxMenuItem mnComboSort;
	private JCheckBoxMenuItem mnShellSort;
	
	public OrdenaListener(Frame f) {
		frameOrdena = f;
	}
	
	public void actionPerformed(ActionEvent e) {

		if (e.getActionCommand().equals("BubbleSort")) {
	    	selecionaBubbleSort();
	    } else if (e.getActionCommand().equals("InsertionSort")) {
	    	selecionaInsertionSort();
	    } else if (e.getActionCommand().equals("SelectionSort")) {
	    	selecionaSelectionSort();
	    } else if (e.getActionCommand().equals("ComboSort")) {
	    	selecionaComboSort();
	    } else if (e.getActionCommand().equals("ShellSort")) {
	    	selecionaShellSort();
	    }
	}

	public void selecionaBubbleSort() {
		  	
		mnBubbleSort.setSelected( true );
		mnInsertionSort.setSelected( false );
		mnSelectionSort.setSelected( false );
		mnComboSort.setSelected( false );
		mnShellSort.setSelected( false );
	}	

	private void selecionaInsertionSort() {
	  	
		mnBubbleSort.setSelected( false );
		mnInsertionSort.setSelected( true );
		mnSelectionSort.setSelected( false );
		mnComboSort.setSelected( false );
		mnShellSort.setSelected( false );
	}	
	
	private void selecionaSelectionSort() {
	  	
		mnBubbleSort.setSelected( false );
		mnInsertionSort.setSelected( false );
		mnSelectionSort.setSelected( true );
		mnComboSort.setSelected( false );
		mnShellSort.setSelected( false );
	}
	
	private void selecionaComboSort() {
	  	
		mnBubbleSort.setSelected( false );
		mnInsertionSort.setSelected( false );
		mnSelectionSort.setSelected( false );
		mnComboSort.setSelected( true );
		mnShellSort.setSelected( false );
	}
	
	private void selecionaShellSort() {
	  	
		mnBubbleSort.setSelected( false );
		mnInsertionSort.setSelected( false );
		mnSelectionSort.setSelected( false );
		mnComboSort.setSelected( false );
		mnShellSort.setSelected( true );
	}	
	
	/**
	 * @return the mnBubbleSort
	 */
	public JCheckBoxMenuItem getMnBubbleSort() {
		return mnBubbleSort;
	}

	/**
	 * @param mnBubbleSort the mnBubbleSort to set
	 */
	public void setMnBubbleSort(JCheckBoxMenuItem mnBubbleSort) {
		this.mnBubbleSort = mnBubbleSort;
	}

	/**
	 * @return the mnComboSort
	 */
	public JCheckBoxMenuItem getMnComboSort() {
		return mnComboSort;
	}

	/**
	 * @param mnComboSort the mnComboSort to set
	 */
	public void setMnComboSort(JCheckBoxMenuItem mnComboSort) {
		this.mnComboSort = mnComboSort;
	}

	/**
	 * @return the mnInsertionSort
	 */
	public JCheckBoxMenuItem getMnInsertionSort() {
		return mnInsertionSort;
	}

	/**
	 * @param mnInsertionSort the mnInsertionSort to set
	 */
	public void setMnInsertionSort(JCheckBoxMenuItem mnInsertionSort) {
		this.mnInsertionSort = mnInsertionSort;
	}

	/**
	 * @return the mnSelectionSort
	 */
	public JCheckBoxMenuItem getMnSelectionSort() {
		return mnSelectionSort;
	}

	/**
	 * @param mnSelectionSort the mnSelectionSort to set
	 */
	public void setMnSelectionSort(JCheckBoxMenuItem mnSelectionSort) {
		this.mnSelectionSort = mnSelectionSort;
	}

	/**
	 * @return the mnShellSort
	 */
	public JCheckBoxMenuItem getMnShellSort() {
		return mnShellSort;
	}

	/**
	 * @param mnShellSort the mnShellSort to set
	 */
	public void setMnShellSort(JCheckBoxMenuItem mnShellSort) {
		this.mnShellSort = mnShellSort;
	}

	
	
}

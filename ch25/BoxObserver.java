//: C25:BoxObserver.java
// Demonstration of Observer pattern using
// Java's built-in observer classes.
import java.awt.*;
import java.awt.event.*;
import java.util.*;

// You must inherit a new type of Observable:
class BoxObservable extends Observable {
    public void notifyObservers(Object b) {
        // Otherwise it won't propagate changes:
        setChanged();
        super.notifyObservers(b);
    }
}

public class BoxObserver extends Frame {
    Observable notifier = new BoxObservable();

    public BoxObserver(int grid) {
        setTitle("Demonstrates Observer pattern");
        setLayout(new GridLayout(grid, grid));
        for (int x = 0; x < grid; x++) {
            for (int y = 0; y < grid; y++) {
                add(new OCBox(x, y, notifier));
            }
        }
    }

    public static void main(String[] args) {
        int grid = 8;

        if (args.length > 0) {
            grid = Integer.parseInt(args[0]);
        }

        Frame f = new BoxObserver(grid);
        
        f.setSize(500, 400);
        f.setVisible(true);
        f.addWindowListener(
            new WindowAdapter() {
                public void windowClosing(WindowEvent e) {
                    System.exit(0);
                }
            }
        );
    }
}

class OCBox extends Canvas implements Observer {
    OCBox(int x, int y, Observable notifier) {
        this.x = x;
        this.y = y;
        notifier.addObserver(this);
        this.notifier = notifier;
        addMouseListener(new ML());
    }

    public void paint(Graphics g) {
        g.setColor(cColor);
        Dimension s = getSize();
        g.fillRect(0, 0, s.width, s.height);
    }

    public void update(Observable o, Object arg) {
        OCBox clicked = (OCBox)arg;
        if (nextTo(clicked)) {
            cColor = clicked.cColor;
            repaint();
        }
    }

    private final boolean nextTo(OCBox b) {
        return Math.abs(x - b.x) <= 1 
            && Math.abs(y - b.y) <= 1;
    }

    int x; // Location in grid
    int y;

    Observable notifier;
    Color cColor = new Color(0, 0, 0);

    static final Color[] colors = {
        Color.black, Color.blue, Color.cyan,
        Color.darkGray, Color.gray, Color.green,
        Color.lightGray, Color.magenta,
        Color.orange, Color.pink, Color.red,
        Color.white, Color.yellow
    };

    static final Color newColor() {
        return colors[(int)(Math.random()*colors.length)];
    };

    class ML extends MouseAdapter {
        public void mousePressed(MouseEvent e) {
            notifier.notifyObservers(OCBox.this);
        }
    }
} ///:~

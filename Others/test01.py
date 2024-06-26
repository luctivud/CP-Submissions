from manimlib import *

class InteractiveDevelopment(Scene):
    def construct(self):
        circle = Circle()
        circle.set_fill(BLUE, opacity=0.5)
        circle.set_stroke(BLUE_E, width=4)
        square = Square()

        self.play(ShowCreation(square))
        self.wait()

        # This opens an iPython termnial where you can keep writing
        # lines as if they were part of this construct method.
        # In particular, 'square', 'circle' and 'self' will all be
        # part of the local namespace in that terminal.
        self.embed()

        # Try copying and pasting some of the lines below into
        # the interactive shell
        self.play(ReplacementTransform(square, circle))
        self.wait()
        self.play(circle.animate.stretch(4, 0))
        self.play(Rotate(circle, 90 * DEGREES))
        self.play(circle.animate.shift(2 * RIGHT).scale(0.25))

        text = Text("""
            In general, using the interactive shell
            is very helpful when developing new scenes
        """)
        self.play(Write(text))

        # In the interactive shell, you can just type
        # play, add, remove, clear, wait, save_state and restore,
        # instead of self.play, self.add, self.remove, etc.

        # To interact with the window, type touch().  You can then
        # scroll in the window, or zoom by holding down 'z' while scrolling,
        # and change camera perspective by holding down 'd' while moving
        # the mouse.  Press 'r' to reset to the standard camera position.
        # Press 'q' to stop interacting with the window and go back to
        # typing new commands into the shell.

        # In principle you can customize a scene to be responsive to
        # mouse and keyboard interactions
        always(circle.move_to, self.mouse_point)

# from src.array_manim import Element, random, swap_elements, SCALE
# from manim import *


# class Bubble(Scene):
#     def construct(self):
#         text = Tex("Bubble Sort", color=YELLOW)
#         self.play(Write(text))
#         self.remove(text)
#         shuffled_arr = [2, 4, 5, 6, 7, 9, 1, 8, 0, 3]
#         random.shuffle(shuffled_arr)
#         els = [Element(n) for n in shuffled_arr]

#         # Create sliding rectangle
#         ctrl_view_rectangle = Rectangle(width=2 * SCALE, height=1 * SCALE,color=GREEN)

#         # Move elements to theier starting positions
#         for i, item in enumerate(els):
#             new_pos = [(-4.9 + i) * SCALE, 0, 0]
#             item.square.move_to(new_pos)
#             item.text.move_to(new_pos)

#         # Show the Creation of the array
#         self.play(*[Create(el.square)
#                     for el in els],  *[Write(el.text) for el in els])

#         # Move the rectangle to its starting postion
#         intial_rect_pos = midpoint(
#             els[0].square.get_center(), els[1].square.get_center()
#         )
#         ctrl_view_rectangle.move_to(intial_rect_pos)

#         # Show the creation of the rectangle
#         self.play(Create(ctrl_view_rectangle))

#         # start Sorting

#         n = len(shuffled_arr)

#         for i in range(n):
            
#             # For each cycle, swapped flag is intially flas
#             swapped = False
#             if i > 0 :
#                 self.remove(i_text)
#                 self.remove(j_text)
#             i_text = Text(f"i = {i}", color=YELLOW).to_corner(DOWN)
#             self.play(Write(i_text))
            
#             # Last i elements are already in place
#             for j in range(n-i-1):
#                 if j > 0 :
#                     self.remove(j_text)
#                 j_text = Tex(f"j = {j}", color=ORANGE).next_to(i_text,UP)    
#                 self.play(Write(j_text))
#                 # traverse the array from 0 to  n-i-1.
#                 # Swap if the element found is greater than the next element
#                 if els[j].val > els[j+1].val:
#                     els[j], els[j+1] = els[j+1], els[j]
#                     swapped = True
#                     self.play(*swap_elements(els[j], els[j + 1]))
                
#                 if j != len(shuffled_arr) - (i + 2):
#                     self.play(ApplyMethod(
#                         ctrl_view_rectangle.shift, RIGHT * SCALE))
            
#             self.play(ApplyMethod(ctrl_view_rectangle.move_to, intial_rect_pos))
#             # IF no two elements were swapped
#             # by inner loop, then break
            
#             if not swapped:
#                 break
        
#         # When we're done, animate a change color to green for all the elements
#         self.play(*[ApplyMethod(el.square.set_color, GREEN_C) for el in els])
#         self.play(ApplyMethod(ctrl_view_rectangle.set_color, GREEN))
#         self.wait(5)
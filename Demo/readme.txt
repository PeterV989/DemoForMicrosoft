While that is building, I should have an app with a blue button
in the center of the window. This should compile without a problem.
This next part will create the UserControl in a folder.

(I am recording this in bits. I will be right back.)

I'm back.

And I'm back again. Sorry, I ran out of storage space which resulted in a bad build completion.
I'm a hobbyist and struggle on.

Back to the task at hand.

As you can see, there is a bad identifier. Except it shouldn't be bad, right?
I'll show you what I discovered:

Sorry about that. Hard to perform "on camera".

As you can see, the generated file "DemoControl.xaml.g.h" exists within a sub folder of "Generated Files".

But the "normal" generated files are simply in the ""Generated Files" sub folder. The relevant
problem is the __has_include("DemoControl.xaml.g.h"). It executes, but that generated file is not
in "Generated Files" because it's in the subfolder. When I was dealing with this last weekend,
I tried to find some place to add that subfolder for ""Included Directories" in the project
properties. But it would never see it. The solution I came up with was to add an ItemGroup element
to the vcxproj file. (My terminology may not be 100% correct, but I think you'll get my
meaning.) In that element, I created a <Copy> task to copy the files from that subfolder to the
"Generated Files" folder.

On a related issue, but not evident here.

When I discovered this, I already had three UserControls in my app. But once I had the UI working
(sort of), I realized things were about to get cluttered. So I created a subfolder and copied those
code files into that folder. I touched up what needed to be touched up (#includes). Somehow,
as a result of this organizing, I decided to put these UserControls into their own Namespace.
Now I discovered two things. A) the namespace was prepended to the generated files. If my namespace
were "NewNS" for those UserControls, then the generated files became "NewNS.DemoControl.g.h", etc.
But, strangely, the generated file within that subfolder, lacked the namespace prepended to its name.
I expected it to be "NewNS.DemoControl.xaml.g.h" but it wasn't. So the last thing I did was to
copy that file up one level AND give it a new name during the copy. I also learned that I must
have a TaskAfter="winrtmd" and a

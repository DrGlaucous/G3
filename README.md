*The following is in markdown format. See the original files on thingiverse at https://www.thingiverse.com/thing:4595035/ and on github (*
**Important note:**
This design is definitely still in its early stages. Files and documentation should be expected to change at any time.   
*
*
After several weeks of possessing a completed prototype, I have finally had a chance to upload this to the public domain.

This device is a pressurized hopper for Nerf rival rounds (HIRs) that can be worn on the user's back and piped into a blaster of choice.

This design preforms a similar function as the ["Proton Pack"](https://outofdarts.com/products/proton-pack-hopper-feed-kit-build-it-yourself-12-5-balls-second), another pressurized round hopper designed by OutOfDarts, however, the systems used by each are designed quite differently from each other *(this is a fancy way of saying that I did not rip off OutOfDarts' design when producing this machine.)*.

My primary inspiration for the functionality of this device is stemmed from [Bui1derBB's take on the design](https://www.reddit.com/r/Nerf/comments/ckqdpb/junk_jank_proton_pack/), primarily its impeller-like agitator.
*
*
##Print Settings:
The parts used for the construction are not optimized for printing, so supports will have to be used. 

I was able to print the vector on a large format printer I have access to, but if you do not have the ability to print 9x12 inch sheets, you may have to split the vector up into smaller parts

There appears to be formatting issue below. Please refer to the github page for more information.
*
*
For refrerence on how the machine should be assembled, please refer to either the exploded photograph or the source file (.skp) included with the archive. 

Electronics are mounted on a 40x70mm perfboard that fits inside the "electronics housing" model. Currently, the ESC hangs out between the brushless motor and the housing, but should remain relatively shielded if the unit is placed into a modified backpack (See the images in the archieve). 

Required Hardware:
* Cheese ball container (used as the primary "tank". Design of this tank may be different for different regions, but it needs to have a mouth roughly 16cm in diameter. The bulk containers distributed by food manufacturer UTZ usutally fit these requirements.
* Arduino nano (or any other small microcontroller)
* 40x70mm perfboard
* Small gauge wire
* plenty of male and female (2.54mm) pin headers
* 5 volt linear regulator
* N-channel MOSFET
* 200 RPM Geartesian motor (I used [this one](https://www.amazon.com/Greartisan-Electric-Reduction-Centric-Diameter/dp/B072R57C56) , but other variants can be used, too. ***Please note that you may have to tweak the motor housing if one of the [offset motors](https://www.amazon.com/Torque-Reversible-Gear-Box-Electric-Replacement/dp/B00T47CKL2) are used***)
* 2205 variant brushless motor and 20-30a ESC (I suggest that [Racestar V1](https://m.racerstar.com/racerstar-racing-edition-2205-br2205-2300kv-2-4s-brushless-motor-red-cw-or-ccw-for-220-250-rc-drone-fpv-racing-p-33.html) motors are used, as that is what the fan is designed around. Once again, if another type is acquired instead, you will have to redesign the fan to fit.)
* 3s LiPo battery with a high enough discharge rate to compensate for motor current draw. 
* 9x12 sheet of craft foam. (this can be any size, but you will need enough to fit all the cutouts onto it. These cutouts go between the parts to make the unit airtight and, as a result, more efficient. )
* plenty of **6-32 x 1 1/4** bolts and nuts. (they can be longer, but not shorter. Some will have to be cut to size.)
* Florist wire or similar, for securing parts. (this is used to secure many things on the pack, such as the lid and tank. In general, it is a useful item to have)

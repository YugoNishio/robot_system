#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/delay.h>

MODULE_AUTHOR("Nishio Yugo");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;

int gpio_pin_list[] = {25, 17};

void sound(int gpio_pin, int sound_time, int no_sound_time) {
	gpio_base[7] = 1 << gpio_pin;
	msleep(sound_time);
	gpio_base[10] = 1 << gpio_pin;
	msleep(no_sound_time);
}

void ainote(int gpio_pin, int ainote_time, int no_ainote_time) {
	gpio_base[7] = 1 << gpio_pin;
	msleep(ainote_time);
	gpio_base[10] = 1 << gpio_pin;
	msleep(no_ainote_time);
}

static ssize_t led_write(struct file* filp, const char* buf, size_t count, loff_t* pos) {
	char c;
	if (copy_from_user(&c, buf, sizeof(char)))
		return -EFAULT;

	if (c == 'a' || c == 'A') {
		sound(25, 100, 100);
		sound(25, 300, 300);
	}
	if (c == 'b' || c == 'B') {
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == 'c' || c == 'C') {
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 100, 300);
	}
	if (c == 'd' || c == 'D') {
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == 'e' || c == 'E') {
		sound(25, 100, 300);
	}
	if (c == 'f' || c == 'F') {
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 100, 300);
	}
	if (c == 'g' || c == 'G') {
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 100, 300);
	}
	if (c == 'h' || c == 'H') {
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == 'i' || c == 'I') {
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == 'j' || c == 'J') {
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 300);
	}
	if (c == 'k' || c == 'K') {
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 300, 300);
	}
	if (c == 'l' || c == 'L') {
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == 'm' || c == 'M') {
		sound(25, 300, 100);
		sound(25, 300, 300);
	}
	if (c == 'n' || c == 'N') {
		sound(25, 300, 100);
		sound(25, 100, 300);
	}
	if (c == 'o' || c == 'O') {
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 300);
	}
	if (c == 'p' || c == 'P') {
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 100, 300);
	}
	if (c == 'q' || c == 'Q') {
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 300, 300);
	}
	if (c == 'r' || c == 'R') {
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 100, 300);
	}
	if (c == 's' || c == 'S') {
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == 't' || c == 'T') {
		sound(25, 300, 300);
	}
	if (c == 'u' || c == 'U') {
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 300, 300);
	}
	if (c == 'v' || c == 'V') {
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 300, 300);
	}
	if (c == 'w' || c == 'W') {
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 300, 300);
	}
	if (c == 'x' || c == 'X') {
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 300, 300);
	}
	if (c == 'y' || c == 'Y') {
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 300, 300);
	}
	if (c == 'z' || c == 'Z') {
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == '1') {	
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 300);
	}
	if (c == '2') {	
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 300);
	}
	if (c == '3') {	
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 300, 300);
	}
	if (c == '4') {	
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 300, 300);
	}
	if (c == '5') {	
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == '6') {	
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == '7') {	
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == '8') {	
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == '9') {	
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 100, 300);
	}
	if (c == '0') {	
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 300);
	}
	if (c == '!') { //SOS	
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 300, 100);
		sound(25, 100, 100);
		sound(25, 100, 100);
		sound(25, 100, 300);
	}
	if (c == '_') {	//337byoshi
		sound(25, 100, 300);
		sound(25, 100, 300);
		sound(25, 100, 200);
		ainote(17, 200, 200);
		sound(25, 100, 300);
		sound(25, 100, 300);
		sound(25, 100, 200);
		ainote(17, 200, 200);
		sound(25, 100, 300);
		sound(25, 100, 300);
		sound(25, 100, 300);
		sound(25, 100, 300);
		sound(25, 100, 300);
		sound(25, 100, 300);
		sound(25, 100, 300);
	}
	//printk(KERN_INFO "recive %c\n", c);
	return 1;
}

static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.write = led_write
};

static int __init init_mod(void) {

	int retval;
	retval = alloc_chrdev_region(&dev, 0, 1, "myled");
	printk(KERN_INFO "%s is loaded.\n", __FILE__);
	if (retval < 0) {
		printk(KERN_ERR "alloc_chrdev_region failed.\n");
		return retval;
	}
	printk(KERN_INFO "%s is loaded. major:%d\n", __FILE__,MAJOR(dev));
	cdev_init(&cdv, &led_fops);
	cdv.owner = THIS_MODULE;
	retval = cdev_add(&cdv, dev, 1);
	if (retval < 0) {
		printk(KERN_ERR "cdev_add failed. major:%d, minor:%d\n",MAJOR(dev),MINOR(dev));
		return retval;
	}
	cls = class_create(THIS_MODULE, "myled");
	if (IS_ERR(cls)) {
		printk(KERN_ERR "class_create failed.");
		return PTR_ERR(cls);
	}
	device_create(cls, NULL, dev, NULL, "myled%d",MINOR(dev));
	gpio_base = ioremap_nocache(0xfe200000, 0xA0);

	const u32 pin = 17;
	const u32 index = pin/10;
	const u32 shift = (pin%10)*3;
	const u32 mask = ~(0x7<<shift);
	gpio_base[index] = (gpio_base[index] & mask) | (0x1 << shift);
	return 0;
}

static void __exit cleanup_mod(void) {
	cdev_del(&cdv);
	device_destroy(cls, dev);
	class_destroy(cls);
	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "%s is unloaded. major:%d\n", __FILE__, MAJOR(dev));
}

module_init(init_mod);
module_exit(cleanup_mod);

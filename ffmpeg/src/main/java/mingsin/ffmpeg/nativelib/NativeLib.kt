package mingsin.ffmpeg.nativelib

class NativeLib {

    /**
     * A native method that is implemented by the 'nativelib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun add(x: Int, y: Int): Int

    external fun mediaInfo(): String

    external fun getDemo(): JniDemo

    companion object {
        // Used to load the 'nativelib' library on application startup.
        init {
            System.loadLibrary("nativelib")
        }
    }
}